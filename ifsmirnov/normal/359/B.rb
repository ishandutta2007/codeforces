n,k = gets.split.map{ |x| x.to_i }

if k == 0 then
    a = (1..n*2).to_a.reverse
else
    a = [1, k+1] | (1..n*2).to_a.reverse
end

a.each do |x| print "#{x} " end and puts
# 
# s = ms = 0
# 
# a.each_index { |i|
#     if i%2 == 0 then
#         s += a[i] - a[i+1]
#         ms += (a[i]-a[i+1]).abs
#     end
# }
# 
# print ms-s.abs, " ", k.*(2)