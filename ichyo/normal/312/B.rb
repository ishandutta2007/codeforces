a, b, c, d = gets.split.map(&:to_i)
pa = 1.0 * a / b
pb = 1.0 * c / d

puts(1.0 / (1.0 - (1.0 - pa) * (1.0 - pb)) * pa)