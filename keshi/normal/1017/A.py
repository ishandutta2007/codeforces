n=int(input())
a=n*[0]
for i in range(n):
    a[i]=[-sum(map(int,input().split())),i+1]
a.sort()
for i in range(n):
    if a[i][1]==1:
        print(i+1)
        break