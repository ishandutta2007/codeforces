#!/usr/bin/ruby

while s = gets
	s.gsub!(/WUB/, " ")
	puts s.gsub(/WUB/, " ").gsub(/^ */, "").gsub(/ *$/, "").gsub(/ +/, " ")
end