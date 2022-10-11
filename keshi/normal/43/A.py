n=int(input())
a=n*[0]
for i in range(n):
    a[i]=input()
b=list(set(a))
if a.count(b[0])>n//2:
    print(b[0])
else:
    print(b[1])