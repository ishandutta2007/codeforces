use std::io;
use std::error::Error;

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

fn main() -> std::result::Result<(), Box<Error>> {
    let n = parse_line!(usize);
    if n == 0 {
        return Err("n = 0".into());
    }

    let a = parse_vec_line!(i32);

    if n != a.len() {
        return Err(format!("n = {} but a.len() = {}", n, a.len()).into());
    }

    let mut dp = vec![[-1; 5]; n];

    dp[n - 1] = [0; 5];
    for i in (0..n-1).rev() {
        if a[i] < a[i + 1] {
            // b[i] < b[i + 1]
            let mut ok = -1;
            for j in (0..5).rev() {
                dp[i][j] = ok;
                if dp[i + 1][j] >= 0 {
                    ok = j as i32;
                }
            }   
        } else if a[i] > a[i + 1] {
            // b[i] > b[i + 1]
            let mut ok = -1;
            for j in 0..5 {
                dp[i][j] = ok;
                if dp[i + 1][j] >= 0 {
                    ok = j as i32;
                }
            }   
        } else {
            // b[i] != b[i + 1]
            for j in 0..5 {
                if dp[i + 1][j] >= 0 {
                    for k in 0..5 {
                        if j != k {
                            dp[i][k] = j as i32;
                        }
                    }
                }
            }
        }
    }

    match dp[0].into_iter().enumerate().find(|p| *p.1 >= 0) {
        Some((j0, _)) => {
            let mut j = j0;
            for i in 0..n-1 {
                print!("{} ", j + 1);
                j = dp[i][j] as usize;
            }
            println!("{}", j + 1)
        },
        None => println!("-1"),
    };

    Ok(())
}