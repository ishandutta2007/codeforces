a = sum(c == '1' for c in raw_input())
b = sum(c == '1' for c in raw_input())
a += a & 1
print 'YES' if a >= b else 'NO'