use std::io;
use std::cmp;
use std::collections::HashMap;

macro_rules! parse_line {
    ($($type:ty),+) => ({
        let mut line = String::new();
        io::stdin().read_line(&mut line)?;
        let mut iter = line.split_whitespace();
        ($(
            iter.next().ok_or("token expected")?.parse::<$type>()?
        ),+)
    })
}
macro_rules! parse_vec_line {
    ($type:ty) => ({
        let mut line = String::new();
        io::stdin().read_line(&mut line)?;
        let mut vec = Vec::new();
        for token in line.split_whitespace() {
            vec.push(token.parse::<u32>()?);
        }
        vec
    })
}

fn main() -> std::result::Result<(), Box<std::error::Error>> {
    let (n, k) = parse_line!(i32, i32);
    let a = parse_vec_line!(i32);

    // println!("n = {}, m = {}, a = {:?}", n, m, a);
    let mut cnt = HashMap::new();
    for x in a {
        *cnt.entry(x).or_insert(0) += 1;
    }

    let maxcnt = cnt.values().max().unwrap_or(&0);
    let dishes = cmp::max(1, (maxcnt + k - 1) / k) * k;
    let utensils = dishes * (cnt.len() as i32);

    // println!("dishes = {:?}", dishes);
    // println!("utensils = {:?}", utensils);
    println!("{}", utensils - n);

    Ok(())
}