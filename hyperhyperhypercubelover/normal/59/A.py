a = input()
print(a.upper() if sum(a.count(x) for x in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ') * 2 > len(a) else a.lower())