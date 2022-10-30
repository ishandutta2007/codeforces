// {{{
// Most templates comes from https://atcoder.jp/contests/nikkei2019-qual/submissions/4098548
#![allow(unused_imports, non_snake_case, unused_macros)]

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

fn run() {
    let (b, k) = read!(usize, usize);
    let mut a = read!([usize]);
    a.reverse();

    let mut cur = 1;
    let mut answer = 0;
    for i in 0..k {
        answer += a[i] * cur;
        cur *= b;
        answer %= 2;
        cur %= 2;
    }
    println!("{}", if answer % 2 == 0 { "even" } else { "odd" });
}