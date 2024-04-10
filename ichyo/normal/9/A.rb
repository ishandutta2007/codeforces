a = gets.split.map(&:to_i).max
puts ["", "1/1", "5/6", "2/3", "1/2", "1/3", "1/6"][a]