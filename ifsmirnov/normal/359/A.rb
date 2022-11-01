def parse(s)
    s = s.split
    for i in 0...s.length do s[i] = s[i].to_i end
    s
end
    
n,m = parse gets
a = []
(0...n).each { |i|
    a << []
    (parse gets).each { |val|
        a[-1] << val
    }   
}

(a[0]+a[-1]).each do |i| if i == 1 then puts 2; exit 0 end end
(0...n).each do |i| if a[i][-1] == 1 or a[i][0] == 1 then puts 2; exit 0 end end
puts 4