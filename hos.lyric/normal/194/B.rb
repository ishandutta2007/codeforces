#!/usr/bin/ruby

def gcd(a, b)
	return (b != 0) ? gcd(b, a % b) : a
end

gets
gets.split.map(&:to_i).each do |n|
	puts (n * 4) / gcd(n * 4, n + 1) + 1
end