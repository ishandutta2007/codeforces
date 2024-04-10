#!/usr/bin/ruby

while line = gets
	n, k, l, c, d, p, nl, np = line.split.map(&:to_i)
	ans = [ k * l / nl, c * d, p / np ].min
	ans /= n
	puts ans
end