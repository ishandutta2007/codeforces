def get():
    return list(map(int,input().split()))
n=int(input())
a=get()
s=max(a)
a.remove(s)
for i in range(1,s//2+1):
    if s%i==0:
        a.remove(i)
print(s,max(a))