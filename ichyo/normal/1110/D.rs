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

fn run() {
    let (n, m) = read!(usize, usize);
    let a = read!([usize]);
    let max = 1_000_010;
    let mut cnt = vec![0; max];
    for x in a {
        cnt[x] += 1;
    }

    let mut dp = [-1isize; 9];
    dp[0] = 0;
    for i in 0..max {
        let mut ndp = [-1isize; 9];
        for j in 0..3 {
            for k in 0..3 {
                let id = j * 3 + k;
                if dp[id] < 0 {
                    continue;
                }
                let used = j + k;
                for next in 0..3 {
                    if next + used > cnt[i] {
                        continue;
                    }
                    let add = (cnt[i] - next - used) / 3 + next;
                    let next_id = next * 3 + j;
                    ndp[next_id].set_max(dp[id] + add as isize);
                }
            }
        }
        dp = ndp;
    }
    println!("{}", dp[0]);
}