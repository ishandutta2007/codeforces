a = input()
b = input()
x = a.count('1')
x = x + x%2
x -= b.count('1')
print("NO" if x < 0 else "YES")