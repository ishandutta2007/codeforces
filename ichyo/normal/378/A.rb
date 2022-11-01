a, b = gets.split.map(&:to_i)

ans = [0, 0, 0]
(1..6).each do |x|
    da = (a - x).abs
    db = (b - x).abs
    if da < db
        ans[0] += 1
    elsif da == db
        ans[1] += 1
    else
        ans[2] += 1
    end
end

puts ans.join(" ")