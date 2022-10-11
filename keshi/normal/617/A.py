n=int(input())
f=0
for i in range(5,0,-1):
    f+=n//i
    n=n%i
print(f)