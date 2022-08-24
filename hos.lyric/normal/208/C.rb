#!/usr/bin/ruby

require 'pp'

inf = 1001001001

while line = gets
	n, m = line.split.map(&:to_i)
	d = Array.new(n)
	n.times do |u|
		d[u] = Array.new(n, inf)
		d[u][u] = 0
	end
	m.times do
		u, v = gets.split.map{|x| x.to_i - 1}
		d[u][v] = d[v][u] = 1
	end
	n.times do |w|
		n.times do |u|
			n.times do |v|
				if  d[u][v] > d[u][w] + d[w][v]
					d[u][v] = d[u][w] + d[w][v]
				end
			end
		end
	end
	e = Array.new(n)
	n.times do |u|
		e[u] = Array.new(n, 0.0)
	end
	n.times do |u|
		n.times do |v|
			if d[u][v] <= 1
				e[u][v] = 1.0
			end
		end
	end
	2.upto(n) do |dist|
		n.times do |u|
			n.times do |v|
				if d[u][v] == dist
					n.times do |w|
						if d[u][w] == 1 && d[u][v] == 1 + d[w][v]
							e[u][v] += e[u][w] * e[w][v]
						end
					end
				end
			end
		end
	end
	# pp e
	ans = 1.0
	n.times do |w|
		if w != 0 && w != n - 1 && d[0][n - 1] == d[0][w] + d[w][n - 1]
			tmp = 2.0 * e[0][w] * e[w][n - 1] / e[0][n - 1]
			# p w
			# p tmp
			if  ans < tmp
				ans = tmp
			end
		end
	end
	p ans
end