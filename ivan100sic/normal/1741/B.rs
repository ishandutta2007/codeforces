fn rdi() -> i32 {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    line.trim().parse::<i32>().unwrap()
}

fn main() {
    let mut t = rdi();
    for _t in 0..t {
        let n = rdi();
        if n == 1 || n == 3 {
            println!("-1")
        } else {
            for i in 3..n+1 {
                print!("{} ", i);
            }
            println!("2 1");
        }
    }
}