def get():
    return map(int,input().split())
n=int(input())
for i in range(n):
    a,b=get()
    print(9*(a-1)+b)