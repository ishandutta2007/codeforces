def com(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return 1
    return 0
n=int(input())
for i in range(2,n//2+1):
    if com(i) and com(n-i):
        print(i,n-i)
        break