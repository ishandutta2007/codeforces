s = raw_input()
a = s.count('a')
b = s.count('b')
c = s.count('c')
print 'YES' if a >= 1 and b >= 1 and (a == c or b == c) and s == 'a'*a + 'b'*b + 'c'*c else 'NO'