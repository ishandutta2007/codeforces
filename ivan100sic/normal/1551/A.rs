use std::io::stdin;

fn ri() -> i32 {
    let mut s = String::new();
    stdin().read_line(&mut s);
    s.trim().parse::<i32>().unwrap()
}
fn main() {
    for _ in 0..ri() {
        let x = ri();
        let (y, z) = match x % 3 {
            0 => (x/3, x/3),
            1 => (x/3+1, x/3),
            _ => (x/3, x/3+1),
        };
        println!("{} {}", y, z);
    }
}