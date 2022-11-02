use std::io;
pub fn read_numbers() -> Vec<u32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    line.split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect()
}

fn main(){
	let numbers = read_numbers();
	let n = numbers[0] as i64;
	let c1 = numbers[1] as i64;
	let c2 =numbers[2] as i64;
	
	let mut res:i64 = 1000000000000000000;
	
	let mut line = String::new();
	io::stdin().read_line(&mut line);
	let mut s1 = 0;
	let mut s2 = 0;
	let char_vec:Vec<char> = line.chars().collect();
	for i in 0..char_vec.len() {
	  if char_vec[i] == '0' {
	    s1 += 1;
	  } else if char_vec[i] == '1' {
	    s2 += 1;
	  }
	}
	
	
	
	for vzr in 1..s2+1 {
	  let sz = n/vzr as i64;
	  let large = n%vzr as i64;
	  let small = vzr-large as i64;
	//  println!("{}*{} + {}*{}", sz, small, sz+1, large);
	  let mut t = (sz-1)*(sz-1)*small*c2 + sz*sz*large*c2 + vzr*c1 as i64;
	  if t < res { res = t; }
	}
	println!("{}", res);

/*
	for item in 0..n{
		let mut cur_line = String::new();
		std::io::stdin().read_line(&mut cur_line)
		.expect("Can't get current line!");

		let cur_line = cur_line.trim();

		if cur_line.chars().count() > 10 {
		println!("{}{}{}", cur_line.chars().nth(0).unwrap(), cur_line.chars().count()-2, cur_line.chars()
			.nth(cur_line.chars().count()-1).unwrap());
		} else {
			println!("{}", cur_line);
		}

	}
	*/

}