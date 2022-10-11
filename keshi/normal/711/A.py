n=int(input())
f=0
b=''
for i in range(n):
    a=input().split('|')
    if not f and'OO' in a:
        f=1
        a[a.index('OO')]='++'
    b+=a[0]+'|'+a[1]+'\n'
if f:
    print("YES")
    print(b)
else:
    print("NO")