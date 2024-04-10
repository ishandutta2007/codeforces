a = raw_input()
print 'Yes' if set('ABC') in map(set, zip(a, a[1:], a[2:])) else 'No'