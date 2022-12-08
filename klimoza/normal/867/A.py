n = int(input())
s = input()
f1= 0
f2 = 0
for i in range(0, n - 1):
    if(s[i] == 'S' and s[i + 1] == 'F'): f2 += 1
    if(s[i] == 'F' and s[i + 1] == 'S'): f1 += 1
if(f2 > f1):
    print("YES")
else:
    print("NO")