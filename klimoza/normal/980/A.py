s = input()
a = 0
b = 0
for i in s:
    if i == "-":
        a += 1
    else:
        b += 1
if b == 0 or a % b == 0:
    print("YES")
else:
    print("NO")