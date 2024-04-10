n = gets.to_i

(0..2 * n).each do |y|
    s = ""
    (0..2 * n).each do |x|
        t = n - (x - n).abs - (y - n).abs
        s += (t >= 0 ? t.to_s : " ")
        s += " "
    end
    puts s.rstrip
end