n = int(input())
a = list(map(int,input().split(" ")))

res = 0
i = 0
while i < len(a):
    if a[i]==1:
        res += 1
        while i<len(a) and a[i]==1:
            i += 1
            res += 1
    i += 1
print(max(0,res-1))