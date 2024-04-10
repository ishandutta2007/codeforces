#!/usr/bin/ruby

m = 53

while line = gets
	n = line.to_i
	cards = gets.split
	as = Array.new(n + 3)
	as[0] = as[1] = as[2] = m - 1
	n.times do |i|
		as[i + 3] = 0
		case cards[i][0]
		when ?2
			as[i + 3] += 0
		when ?3
			as[i + 3] += 1
		when ?4
			as[i + 3] += 2
		when ?5
			as[i + 3] += 3
		when ?6
			as[i + 3] += 4
		when ?7
			as[i + 3] += 5
		when ?8
			as[i + 3] += 6
		when ?9
			as[i + 3] += 7
		when ?T
			as[i + 3] += 8
		when ?J
			as[i + 3] += 9
		when ?Q
			as[i + 3] += 10
		when ?K
			as[i + 3] += 11
		when ?A
			as[i + 3] += 12
		end
		case cards[i][1]
		when ?S
			as[i + 3] += 0
		when ?D
			as[i + 3] += 13
		when ?H
			as[i + 3] += 26
		when ?C
			as[i + 3] += 39
		end
	end
# p as
	dp = Array.new(n + 1)
	dp.length.times do |i|
		dp[i] = Array.new(m * m * m)
	end
	dp[n][(as[n] * m + as[n + 1]) * m + as[n + 2]] = true
	n.downto(2) do |i|
		dp[i].length.times do |p|
			if dp[i][p]
				x0 = p % m
				x1 = p / m % m
				x2 = p / m / m % m
				x3 = as[i - 1]
				if x1 != m - 1 && (x1 % 13 == x0 % 13 || x1 / 13 == x0 / 13)
					dp[i - 1][(x3 * m + x2) * m + x0] = true
				end
				if x3 != m - 1 && (x3 % 13 == x0 % 13 || x3 / 13 == x0 / 13)
					dp[i - 1][(x0 * m + x2) * m + x1] = true
				end
			end
		end
	end
	ans = false
	dp[1].length.times do |p|
		ans = ans || dp[1][p]
	end
	puts ans ? "YES" : "NO"
end