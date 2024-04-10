def prime?(num)
  2.upto(num-1){|i|
    if num % i == 0
      return false  
    end
  }
  return true
end
p = Array.new
i = 2
while p.length < 50
  if prime?(i)
    p << i
  end
  i += 1
end
n = gets.to_i
if n!=2
  for i in 0...n
    ans = 1
    for j in 0...n-1
      ans *= p[(i+j)%n]
    end
    puts ans
  end
else 
  puts -1
end