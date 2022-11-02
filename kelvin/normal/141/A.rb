#!/usr/bin/env ruby

$ma = {}
$ma.default = 0

gets.strip.split('').each { |c| $ma[c]+=1 }
gets.strip.split('').each { |c| $ma[c]+=1 }
gets.strip.split('').each { |c| $ma[c]-=1 }

flag = true;
$ma.each { |c,d|
   flag = false if d!=0
}

puts (flag ? "YES" : "NO")