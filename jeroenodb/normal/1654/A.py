n_test=int(input())
for i in range(n_test):
    n = int(input())
    vals = sorted([int(i) for i in input().split()])
    s = sum(vals[-2:])
    print(s)