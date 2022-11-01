def f(y)
    a = []
    while y > 0
        a << y % 10
        y /= 10
    end
    return a.sort.uniq == a.sort
end
y = gets.to_i

y = y + 1
loop do
    break if f y
    y = y + 1
end
puts y