#!/usr/bin/ruby

while line = gets
	n = line.to_i
	ps = gets.split.map(&:to_i)
	as = gets.split.map(&:to_i)
	ans = Array.new(as.length, 0)
	now = 0
	ps.each do |p|
		now += p
		(as.length - 1).downto(0) do |i|
			tmp = now / as[i]
			ans[i] += tmp
			now -= tmp * as[i]
		end
	end
	as.length.times do |i|
		if i > 0
			print " "
		end
		print ans[i]
	end
	puts
	puts now
end