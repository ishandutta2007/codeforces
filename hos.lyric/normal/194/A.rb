#!/usr/bin/ruby

while line = gets
	n, k = line.split.map(&:to_i)
	ans = [ n * 3 - k, 0 ].max
	puts ans
end