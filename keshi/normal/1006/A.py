def m(n):
    return int(n)-(int(n)-1)%2
n= int(input())
print(*list(map(m,input().split())))