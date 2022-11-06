n, k = [int(i) for i in input().split()]

print(sum(i.count("4") + i.count("7") <= k for i in input().split()))