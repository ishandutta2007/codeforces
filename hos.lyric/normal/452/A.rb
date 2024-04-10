#!/usr/bin/ruby

gets
p = gets.chomp
["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"].each do |s|
  if Regexp.new("^" + p + "$") =~ s then
    puts s
  end
end