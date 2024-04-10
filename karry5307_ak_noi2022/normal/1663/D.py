s, x = input(), int(input())
if s.lower() == 'abc':
    print('YES' if x < 2000 else 'NO')
elif s.lower() == 'arc':
    print('YES' if x < 2800 else 'NO')
elif s.lower() == 'agc':
    print('YES' if x >= 1200 else 'NO')
else:
    print('YES')