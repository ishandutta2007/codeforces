n=int(input())
a=input()
b=input()
f=0
for i in range(n):
    c=int(a[i])-int(b[i])
    f+=min(abs(c),abs(c+10),abs(c-10))
print(f)