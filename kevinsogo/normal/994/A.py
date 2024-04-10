input()
a = map(int, input().split())
print(*filter(list(map(int, input().split())).count, a), sep=' ')