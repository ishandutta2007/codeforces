n = gets.to_i
n.times do 
    s = gets.strip
    s = s[0, 1] + (s.size - 2).to_s + s[-1, 1] if s.size > 10
    puts s
end