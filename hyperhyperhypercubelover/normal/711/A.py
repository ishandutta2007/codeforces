n = int(input())
a = '\n'.join(input() for _ in range(n))
print('YES\n' + a.replace('OO', '++', 1) if a.find('OO') != -1 else 'NO')