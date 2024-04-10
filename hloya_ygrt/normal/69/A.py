n = int(input())
x = 0
y = 0
z = 0
for i in range(n):
    s = input().split()
    x += int(s[0])
    y += int(s[1])
    z += int(s[2])
if x*y == z*x and z * x == z*y and x * y == z * y and y == 0:
    print("YES")
else:
    print("NO")