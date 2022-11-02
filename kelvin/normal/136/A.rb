#!/usr/bin/env ruby

gets
m = {}
gets.split.map(&:to_i).each_with_index { |p,i|
   m[p] = i
}
m.map.sort_by{ |i,p|i }.map { |i,p|
   print "#{p+1} "
}
puts