use std::io;
use std::cmp;
use std::collections::HashMap;
use std::error::Error;

fn main() -> std::result::Result<(), Box<Error>> {
    let mut s = String::new();
    io::stdin().read_line(&mut s)?;
    let s = s.trim();

    let rows = (s.len() + 19) / 20;
    let columns = (s.len() + rows - 1) / rows;

    println!("{} {}", rows, columns);
    for row in 0..rows {
        let lb = row * s.len() / rows;
        let rb = (row + 1) * s.len() / rows;
        println!("{}{}", &s[lb..rb],
                 if rb - lb == columns { "" } else { "*" })
    }

    Ok(())
}