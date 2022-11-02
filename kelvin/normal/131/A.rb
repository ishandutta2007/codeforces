#!/usr/bin/env ruby

def isupper(str)
   str.upcase == str
end

def islower(str)
   str.downcase == str
end

def withcap(str)
   isupper(str) || islower(str[0..0]) && isupper(str[1..-1])
end

str = gets
str.swapcase! if withcap(str)
puts str