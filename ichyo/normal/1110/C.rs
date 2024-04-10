// {{{
// Most templates comes from https://atcoder.jp/contests/nikkei2019-qual/submissions/4098548
#![allow(unused_imports, non_snake_case)]

macro_rules! eprint {
	($($t:tt)*) => {{
		use ::std::io::Write;
		let _ = write!(::std::io::stderr(), $($t)*);
	}};
}

macro_rules! eprintln {
	() => { eprintln!(""); };
	($($t:tt)*) => {{
		use ::std::io::Write;
		let _ = writeln!(::std::io::stderr(), $($t)*);
	}};
}

pub trait SetMinMax {
    fn set_min(&mut self, v: Self) -> bool;
    fn set_max(&mut self, v: Self) -> bool;
}

impl<T> SetMinMax for T
where
    T: PartialOrd,
{
    fn set_min(&mut self, v: T) -> bool {
        *self > v && {
            *self = v;
            true
        }
    }
    fn set_max(&mut self, v: T) -> bool {
        *self < v && {
            *self = v;
            true
        }
    }
}

macro_rules! dbg {
    ($val:expr) => {
        match $val {
            tmp => {
                eprintln!(
                    "[{}:{}] {} = {:#?}",
                    file!(),
                    line!(),
                    stringify!($val),
                    &tmp
                );
                tmp
            }
        }
    };
}

pub fn readln() -> String {
    let mut line = String::new();
    ::std::io::stdin()
        .read_line(&mut line)
        .unwrap_or_else(|e| panic!("{}", e));
    line
}

macro_rules! read {
	($($t:tt),*; $n:expr) => {{
		let stdin = ::std::io::stdin();
		let ret = ::std::io::BufRead::lines(stdin.lock()).take($n).map(|line| {
			let line = line.unwrap();
			let mut it = line.split_whitespace();
			_read!(it; $($t),*)
		}).collect::<Vec<_>>();
		ret
	}};
	($($t:tt),*) => {{
		let line = readln();
		let mut it = line.split_whitespace();
		_read!(it; $($t),*)
	}};
}

macro_rules! _read {
	($it:ident; [char]) => {
		_read!($it; String).chars().collect::<Vec<_>>()
	};
	($it:ident; [u8]) => {
		Vec::from(_read!($it; String).into_bytes())
	};
	($it:ident; [$t:ty]) => {
		$it.map(|s| s.parse::<$t>().unwrap_or_else(|e| panic!("{}", e))).collect::<Vec<_>>()
	};
	($it:ident; $t:ty) => {
		$it.next().unwrap_or_else(|| panic!("input mismatch")).parse::<$t>().unwrap_or_else(|e| panic!("{}", e))
	};
	($it:ident; $($t:ty),+) => {
		($(_read!($it; $t)),*)
	};
}

// }}}

fn main() {
    let _ = ::std::thread::Builder::new()
        .name("run".to_string())
        .stack_size(32 * 1024 * 1024)
        .spawn(run)
        .unwrap()
        .join();
}

use std::cmp::{max, min};
use std::collections::{HashMap, HashSet, VecDeque};

fn gcd(x: usize, y: usize) -> usize {
    if y == 0 {
        x
    } else {
        gcd(y, x % y)
    }
}

fn calc(a: usize, b: usize) -> usize {
    gcd(a ^ b, a & b)
}

fn answer(a: usize) -> usize {
    let mut answer = 0;
    for i in 1..a {
        let c = calc(a, i);
        answer.set_max(c);
    }
    answer
}

fn run() {
    let mut memo = HashMap::new();
    for a in 2..100 {
        memo.insert(a, answer(a));
    }
    memo.insert(7, 1);
    memo.insert(15, 5);
    memo.insert(31, 1);
    memo.insert(63, 21);
    memo.insert(127, 1);
    memo.insert(255, 85);
    memo.insert(511, 73);
    memo.insert(1023, 341);
    memo.insert(2047, 89);
    memo.insert(4095, 1365);
    memo.insert(8191, 1);
    memo.insert(16383, 5461);
    memo.insert(32767, 4681);
    memo.insert(65535, 21845);
    memo.insert(131071, 1);
    memo.insert(262143, 87381);
    memo.insert(524287, 1);
    memo.insert(1048575, 349525);
    memo.insert(2097151, 299593);
    memo.insert(4194303, 1398101);
    memo.insert(8388607, 178481);
    memo.insert(16777215, 5592405);
    memo.insert(33554431, 1082401);
    /*
    for i in 3..=25 {
        let b = (1 << i);
        println!("memo.insert({}, {});", b - 1, answer(b - 1));
    }
    */
    let q = read!(usize);
    for _ in 0..q {
        let x = read!(usize);
        if memo.contains_key(&x) {
            println!("{}", memo[&x]);
        } else {
            let mut b = 2;
            while !(x < b) {
                b *= 2;
            }
            println!("{}", b - 1);
        }
    }
}