n = int(input())

x = set(map(int, input().split(" ")))

for i in range(1,n+1):
    if i not in x:
        print(i)