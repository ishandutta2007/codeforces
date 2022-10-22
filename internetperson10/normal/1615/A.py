t = int(input())
for _ in range(t):
    n = int(input())
    l = input().split()
    l = [int(x) for x in l]
    if sum(l) % n == 0:
        print(0)
    else:
        print(1)