n = gets.to_i
v = gets.split.map(&:to_i)
ans = v.map.with_index.to_a.sort{ |a, b| b[0] <=> a[0] }
puts "#{ans[0][1] + 1} #{ans[1][0]}"