input()
a=list(input())
for i in range(len(a)):
    if a[i]>"Z":
        a[i]=chr(ord(a[i])-32)
a=set(a)
if len(a)==26:
    print("YES")
else:
    print("NO")