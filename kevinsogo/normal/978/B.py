input()
print(sum(max(0, len(r) - 2) for r in ''.join(' x'[x == 'x'] for x in input()).split()))