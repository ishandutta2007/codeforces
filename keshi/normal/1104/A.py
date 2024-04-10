def get():
    return list(map(int,input().split()))
n=int(input())
a=n*[1]
print(n)
print(*a)