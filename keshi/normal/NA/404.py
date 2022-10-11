b=input()
a=input().split()
f=0
for i in a:
    if i[0]==b[0] or i[1]==b[1]:
        f=1
        break
if f:
    print("YES")
else:
    print("NO")