#!/usr/bin/ruby

while line = gets
	a, b, r = line.split.map(&:to_i)
	puts ([ a, b ].min >= r * 2) ? "First" : "Second"
end