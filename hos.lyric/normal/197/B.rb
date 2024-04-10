#!/usr/bin/ruby

def gcd(a, b)
	return (b != 0) ? gcd(b, a % b) : a
end

while line = gets
	m, n = line.split.map(&:to_i)
	as = gets.split.map(&:to_i)
	bs = gets.split.map(&:to_i)
	if m > n
		puts (as[0] * bs[0] < 0) ? "-Infinity" : "Infinity"
	elsif m < n
		puts "0/1"
	else
		p = as[0]
		q = bs[0]
		g = gcd(p, q);
		p /= g
		q /= g
		if q < 0
			p *= -1
			q *= -1
		end
		puts "#{p}/#{q}"
	end
end